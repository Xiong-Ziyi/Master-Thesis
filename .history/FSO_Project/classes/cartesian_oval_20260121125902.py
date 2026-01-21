import numpy as np
from scipy.optimize import least_squares
import matplotlib.pyplot as plt

from .surfaces import EvenAsphere

class CartesianOvalCollimator:
    '''
    This class models a Cartesian oval collimator defined by the point source distance and refractive index.
    '''
    
    def __init__(self, z_0, n, r_max, num_samples=100):
        if n <= 1:
            raise ValueError(f"Refractive index n must be greater than 1, got {n}")
        if z_0 <= 0:
            raise ValueError(f"Point source distance z_0 must be positive, got {z_0}")
        if r_max <= 0:
            raise ValueError(f"Maximum radius r_max must be positive, got {r_max}")
        
        self.z_0 = z_0
        self.n = n
        self.r_max = r_max
        self.num_samples = num_samples
        self.r = np.linspace(0, r_max, num_samples)
        
    def sag(self) -> np.ndarray:
        term1 = self.r**2 / (self.n**2 - 1)
        term2 = self.z_0 / (self.n + 1)
        
        sag = np.sqrt(term1 + term2**2) - term2
        return sag
    
    def plot_sag(self):
        z_r = self.sag()
        plt.figure(figsize=(8, 5))
        plt.plot(self.r, z_r, label='Cartesian Oval Sag', color='blue')
        plt.xlabel('Radial Coordinate (r)')
        plt.ylabel('Sag z(r)')
        plt.title('Sag of Cartesian Oval Collimator')
        plt.legend()
        plt.grid()
        plt.show()
        
    def even_aspheric_fitting(self, 
                              ea: EvenAsphere,
                              bounds: dict = {'vertex_r_min': -10000, 'vertex_r_max': 10000, 'k_min': -100, 'k_max': 100},
                              verbose: bool = False,
                              compare: bool = False 
                              ) -> EvenAsphere:
        
        
        
        if ea.r_max != self.r_max:
            raise ValueError("Even aspheric r_max must be equal to Cartesian val r_max.")
        
        if ea.num_samples != self.num_samples:
            raise ValueError("Even aspheric num_samples must be equal to Cartesian oval num_samples.")
        
        z_data = self.sag()
        
        coeffs_list = [ea.coefficients.get(order, 0.0) for order in sorted(ea.coefficients.keys())]
        p0 = [ea.vertex_r, ea.k] + coeffs_list
        
        num_coeffs= len(coeffs_list)
        
        lb = [bounds['vertex_r_min'], bounds['k_min']] + [-np.inf]*num_coeffs
        ub = [bounds['vertex_r_max'], bounds['k_max']] + [np.inf]*num_coeffs
        
        bounds_tuple = (lb, ub)
        
        def residuals(params):
            '''
            Computes the residuals between the data and the fitted aspheric surface for later optimization.
            
            Args:
                params: 1D vector
                
            Returns:
                Residuals between the fitted aspheric surface sag and the Cartesian oval sag.   
            '''
            vertex_r_fit = params[0]   
            k_fit = params[1]
            coeffs_fit = {4 + 2*i: params[2 + i] for i in range(num_coeffs)}
            
            ea_fit = EvenAsphere(r_max=self.r_max, 
                                 vertex_r=vertex_r_fit,
                                 k=k_fit,
                                 coefficients=coeffs_fit,
                                 num_samples=self.num_samples)
            
            z_fit = ea_fit.sag()
            
            return z_fit - z_data
        
        result = least_squares(residuals, p0, bounds=bounds_tuple, method='trf', ftol=1e-8, xtol=1e-8, gtol=1e-8, verbose=2 if verbose else 0)
        
        fitted_params = result.x
        vertex_r_fitted = fitted_params[0]
        k_fitted = fitted_params[1]
        coeffs_fitted = {4 + 2*i: fitted_params[2 + i] for i in range(num_coeffs)}
        
        if compare:
            ea_fitted = EvenAsphere(r_max=self.r_max,
                                    vertex_r=vertex_r_fitted,
                                    k=k_fitted,
                                    coefficients=coeffs_fitted,
                                    num_samples=self.num_samples)
            
            z_fitted = ea_fitted.sag()
            
            plt.figure(figsize=(10, 6))
            plt.plot(self.r, z_data, label='Cartesian Oval Sag', linewidth=2)
            plt.plot(self.r, z_fitted, '--', label='Fitted Even Aspheric Sag', linewidth=2)
            plt.xlabel('Radial Coordinate (r)')
            plt.ylabel('z(r)')
            plt.title('Comparison of Cartesian Oval and Fitted Even Aspheric Sag')
            plt.legend()
            plt.grid()
            plt.show()
            
        return EvenAsphere(r_max=self.r_max,
                           vertex_r=vertex_r_fitted,
                            k=k_fitted,
                            coefficients=coeffs_fitted,
                            num_samples=self.num_samples)