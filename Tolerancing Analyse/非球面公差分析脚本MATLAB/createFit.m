function [fitresult, gof] = createFit(x, yy)
%CREATEFIT(X,YY)
%  Create a fit.
%
%  Data for 'untitled fit 1' fit:
%      X Input : x
%      Y Output: yy
%  Output:
%      fitresult : a fit object representing the fit.
%      gof : structure with goodness-of fit info.
%
%  另请参阅 FIT, CFIT, SFIT.

%  由 MATLAB 于 28-Jan-2021 09:49:26 自动生成


%% Fit: 'untitled fit 1'.
[xData, yData] = prepareCurveData( x, yy );

% Set up fittype and options.
ft = fittype( '((c*r^2)/(1+sqrt(1-(1+k)*c^2*r^2)))+a1*r^2+a2*r^4+a3*r^6+a4*r^8', 'independent', 'r', 'dependent', 'y' );
opts = fitoptions( 'Method', 'NonlinearLeastSquares' );
opts.Algorithm = 'Levenberg-Marquardt';
opts.Display = 'Off';
opts.StartPoint = [0.01 0.0001 1e-06 1e-08 -0.02 -1];

% Fit model to data.
[fitresult, gof] = fit( xData, yData, ft, opts );

% % Create a figure for the plots.
% figure( 'Name', 'untitled fit 1' );
% 
% % Plot fit with data.
% subplot( 2, 1, 1 );
% h = plot( fitresult, xData, yData );
% legend( h, 'yy vs. x', 'untitled fit 1', 'Location', 'NorthEast' );
% % Label axes
% xlabel x
% ylabel yy
% grid on

% % Plot residuals.
% subplot( 2, 1, 2 );
% h = plot( fitresult, xData, yData, 'residuals' );
% legend( h, 'untitled fit 1 - residuals', 'Zero Line', 'Location', 'NorthEast' );
% % Label axes
% xlabel x
% ylabel yy
% grid on


