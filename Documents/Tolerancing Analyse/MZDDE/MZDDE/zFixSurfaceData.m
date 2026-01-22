function Reply = zFixSurfaceData(Surfaces, Codes)
% zFixSurfaceData - Make lens surface data fixed.
%
% Usage : Reply = zFixSurfaceData(Surfaces, Codes)
%
% Surfaces is a vector of numbers of surfaces which should be fixed. Code is the surface parameter which should be made
% fixed. The codes are the same as for the zSetSolve function as follows :
%
%  ------------------------|------------------------------------------------|
%  zSetSolve Code         -|- Returned data format                          |
%  ------------------------|------------------------------------------------|
%  0, curvature           -|- solvetype, parameter1, parameter2             |
%  1, thickness           -|- solvetype, parameter1, parameter2, parameter3 |
%  2, glass               -|- solvetype, pickupsurf                         |
%  3, semi-diameter       -|- solvetype, pickupsurf                         |
%  4, conic               -|- solvetype, pickupsurf                         |
%  5-12, parameters 1-8   -|- solvetype, pickupsurf, offset, scalefactor    |
%  1001+, extra data values|- solvetype, pickupsurf, scalefactor            |
% -------------------------|------------------------------------------------|
% 
% e.g. zFixSurfaceData(1:4, 0:2) will set curvatures, thicknesses and glasses for surfaces 1 to 4 to fixed mode.
% 
% See also : zSetSolve, zFixAllSurfaceData
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
% $Revision: 1.1 $
% $Author: dgriffith $

for Surf = Surfaces
  for Code = Codes
    switch Code
       case {0},    Reply = zSetSolve(Surf, Code, 0, 0, 0);    
       case {2, 4}, Reply = zSetSolve(Surf, Code, 0, 0); 
       case {3},    Reply = zSetSolve(Surf, Code, 1, 0);
       case {1, 5, 6, 7, 8, 9, 10, 11, 12}, Reply = zSetSolve(Surf, Code, 0, 0, 0, 0);
       otherwise,   Reply = zSetSolve(Surf, Code, 0, 0, 0);
    end
  end
end
