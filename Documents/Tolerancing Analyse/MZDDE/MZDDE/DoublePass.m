function Status = DoublePass(j,k)
% DoublePass - Put a lens into double pass.
%
% Usage : Status = DoublePass(j, k)
%
% Takes a series of surfaces (j thru k) and puts them into double pass,
% mainly with the help of pickups.
% Surface k will typically be a mirror surface. If not, the ray path is
% merely reversed. Note the following ...
% 1) Inserts surfaces k+1 to 2k-j. This is a total of k-j surfaces.
% 2) Inserts pickups of thickness, radius, conic constant, glass, semi-diameter
%    and all lens data parameters. Coatings are copied to the new surfaces.
% 3) Radii, conic constant and parameter pickups are inserted without a sign
%    change.
% 4) Thickness pickups are inserted with sign change.
% 5) Coordinate break surfaces are forced to a reverse order with a pickup 
%    having a scale factor of -1 and an offset of 1 for the mode flag. This 
%    only works properly if you use a mode of 0 or 1 to indicate the order.
% 6) Folds or other z reversals may not be handled correctly in all cases,
%    but seem to work in simple cases.
% 7) Many cases seem to be handled correctly, but check your model
%    carefully. A sensitive test is to put the
%    system into double pass without a mirror. Any ray should be exactly
%    reversed through the system.
% 8) User-defined apertures are not dealt with. Other apertures are kind of
%    fudged by copying some stuff and picking up other stuff.
% 9) Non-sequentials ? You are right out of luck. Why would you want that ?
% 10) This function should leave all existing surfaces untouched except surface k.
%     Otherwise only newly inserted surfaces are
%     meddled with. Suggest you save the lens before doing this.
% 11) If there are multi-configuration parameters applicable to the image
%     surface, and k is the image surface
%     you will probably not get what you want. Other multi-configuration
%     systems should come through ok.
% 12) The image surface can be a mirror surface, and this is useful when
%     going into double pass, if only to
%     put the mirror in automatically where the path reverses.
%
% The following surfaces types are explicitly handled or often work
% correctly. Others may also work.
% STANDARD, EVENASPH, ODDASPHE, COORDBRK, PARAXIAL, PARAX_XY, TILTSURF,
% TOROIDAL
% Surfaces requiring extra data will not work.
% 
% The returned Status is an integer which has the following meaning
%
% 0 - Everything seems to have gone OK.
% 1 - Final surface (k) exceeds the number of surfaces - k assumed to be the image surface.
% 2 - First surface (j) coincident or beyond last surface (k) - you have been ignored.
% 3 - A surface type which is not explicitly supported was encountered - check your results.
%

% MZDDE - The ZEMAX DDE Toolbox for Matlab.
% Copyright (C) 2002-2004 Defencetek, CSIR
% Contact : dgriffith@csir.co.za
% 
% This file is part of MZDDE.
% 
%  MZDDE is free software; you can redistribute it and/or modify
%  it under the terms of the GNU General Public License as published by
%  the Free Software Foundation; either version 2 of the License, or
%  (at your option) any later version.
%
%  MZDDE is distributed in the hope that it will be useful,
%  but WITHOUT ANY WARRANTY; without even the implied warranty of
%  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
%  GNU General Public License for more details.
%
%  You should have received a copy of the GNU General Public License
%  along with MZDDE (COPYING.html); if not, write to the Free Software
%  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
%


% Copyright 2002, Defencetek, CSIR
% $Revision: 1.4 $
% $Author: dgriffith $

global newsurf oldsurf
lensys = zsGetSystem; Im = lensys.numsurfs;
Status = 0;
if (k > Im)
    Status = 1; k = Im;
end
if (j >= k)
    Status = 2; return;
end

% If the last surface is the image surface some special measures have to be taken because
% ZEMAX will not allow insertion of a surface after the image surface.
if (k == Im)
    % Insert a surface before the image surface
    zInsertSurface(k);
    lensys = zsGetSystem; Im = lensys.numsurfs;
    % Copy image surface shape to penultimate surface, both basic data and parameter data
    basicsurfdata = zsGetSurfaceData(Im); surfparams = zGetSurfaceParamVector(Im);
    zsSetSurfaceData(k,basicsurfdata); zSetSurfaceParamVector(k,surfparams);
    % Now make the image surface a standard flat surface.
    basicsurfdata.type = 'STANDARD';
    basicsurfdata.curvature = 0.0;
    basicsurfdata.glass = '';
    basicsurfdata.conic = 0.0;
    zsSetSurfaceData(Im, basicsurfdata);
end
    
% The index newsurf points to the newly inserted surface
% The index oldsurf points to the surface from which the parameters must be
% copied (besides thickness and glass type).
oldsurf = k - 1;
for newsurf = (k+1):(2*k-j)
    % Insert the new surface
    zInsertSurface(newsurf);
    
    % First set the surface type the same as the old surface
    zSetSurfaceData(newsurf, 0, zGetSurfaceData(oldsurf, 0));
    
    % Put in a thickness pickup to the corresponding surface
    zSetSolve(newsurf-1, 1, 5, oldsurf, -1, 0);
    
    % There does not seem to be a way to pickup the aperture, so we do the next best thing and copy
    % the aperture type and values from the oldsurf to the newsurf.
    % Set the aperture parameters the same.
    zsSetAperture(newsurf, zsGetAperture(oldsurf));
    
    % Pickup the semi-diameter from the oldsurf
    zSetSolve(newsurf, 3, 2, oldsurf);
    
    % Copy the coating to the new surface, ZEMAX does not seem to have pickups
    zSetSurfaceData(newsurf, 7, zGetSurfaceData(oldsurf, 7));
    
    % Now insert other pickups according to the type of surface we are dealing with
    surftype = zGetSurfaceData(newsurf,0);
    switch surftype, % Some of these gymnastics may be unnecessary ... 
        case {'STANDARD'}, BasicSolves;
            
        case {'COORDBRK'}, zSetSolve(newsurf, 5, 2, oldsurf, 0, -1);
                           zSetSolve(newsurf, 6, 2, oldsurf, 0, -1);
                           zSetSolve(newsurf, 7, 2, oldsurf, 0, -1);
                           zSetSolve(newsurf, 8, 2, oldsurf, 0, -1);
                           zSetSolve(newsurf, 9, 2, oldsurf, 0, -1);
                           zSetSolve(newsurf, 10, 2, oldsurf, 1, -1);
                           
        case {'PARAXIAL', 'PARAX_XY', 'TILTSURF'}, BasicSolves;
                                                   zSetSolve(newsurf, 5, 2, oldsurf, 0, 1);
                                                   zSetSolve(newsurf, 6, 2, oldsurf, 0, 1);
                                                   
        case {'TOROIDAL', 'EVENASPH', 'ODDASPHE'}, BasicSolves; ParmSolvesPos
            
        otherwise, BasicSolves; ParmSolvesPos; Status = 3;    
    end % dealing with different surface types
    % Now shift back the surface from which the data is copied
    oldsurf = oldsurf - 1;
    lensys = zsGetSystem; Im = lensys.numsurfs;
end



function BasicSolves
% Put in the basic curvature, glass and conic constant pickups
global newsurf oldsurf
zSetSolve(newsurf, 0, 4, oldsurf, 1, 0);
glass = zGetSurfaceData(newsurf - 1, 4);
if (strcmp(glass, 'MIRROR') == 0), zSetSolve(newsurf - 1, 2, 2, oldsurf); end;
glass = zGetSurfaceData(oldsurf, 4);
if (strcmp(glass, 'MIRROR') ~= 0), zSetSolve(newsurf, 2, 2, oldsurf); end; 
zSetSolve(newsurf, 4, 2, oldsurf, 1);



function ParmSolvesPos
global newsurf oldsurf
zSetSolve(newsurf, 5, 2, oldsurf, 0, -1);
zSetSolve(newsurf, 6, 2, oldsurf, 0, -1);
zSetSolve(newsurf, 7, 2, oldsurf, 0, -1);
zSetSolve(newsurf, 8, 2, oldsurf, 0, -1);
zSetSolve(newsurf, 9, 2, oldsurf, 0, -1);
zSetSolve(newsurf, 10, 2, oldsurf, 0, -1);
zSetSolve(newsurf, 11, 2, oldsurf, 0, -1);
zSetSolve(newsurf, 12, 2, oldsurf, 0, -1);
zSetSolve(newsurf, 13, 2, oldsurf, 0, -1);
zSetSolve(newsurf, 14, 2, oldsurf, 0, -1);
zSetSolve(newsurf, 15, 2, oldsurf, 0, -1);
zSetSolve(newsurf, 16, 2, oldsurf, 0, -1);
    
    
    
    
    
