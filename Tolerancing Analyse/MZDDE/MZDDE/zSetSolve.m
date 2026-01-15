function SolveData = zSetSolve(Surface, Code, SolveType, varargin)
% zSetSolve - Sets data for solves and/or pickups on lens surfaces.
%
% Usage : SolveData = zSetSolve(Surface, Code, SolveType, Parameter1, ...)
%
% where Surface is the surface number at which the solve is to be set and Code is
% an integer code indicating which parameter the solve data is for. The solve data is specified in the following
% formats, depending upon the code value according to the following table. The solve takes up to
% three parameters, also depending on the type of solve.
% ------------------------|------------------------------------------------|
% zSetSolve Code         -|- Returned data format                          |
% ------------------------|------------------------------------------------|
% 0, curvature           -|- solvetype, parameter1, parameter2             |
% 1, thickness           -|- solvetype, parameter1, parameter2, parameter3 |
% 2, glass               -|- solvetype, pickupsurf                         |
% 3, semi-diameter       -|- solvetype, pickupsurf                         |
% 4, conic               -|- solvetype, pickupsurf                         |
% 5-12, parameters 1-8   -|- solvetype, pickupsurf, offset, scalefactor    |
% 1001+, extra data values|- solvetype, pickupsurf, scalefactor            |
%-------------------------|------------------------------------------------|
% The solvetype is an integer code, and the parameters have meanings that depend upon the solve type; see
% the chapter "Solves" for details. The Introduction gives a summary for the various solve types.
% Note that code 5 corresponds to parameter 1, not 0. It is not possible to set a solve on parameter
% number 0.
%
% See also zGetSolve.
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

global ZemaxDDEChannel ZemaxDDETimeout
% Decide how many parameters there should be in the input arguments.
%switch Code
%  case {0},       Numerics = 2; 
%  case {2, 3, 4}, Numerics = 1;
%  case {1, 5, 6, 7, 8, 9, 10, 11, 12}, Numerics = 3;
%  otherwise,      Numerics = 2;
%end
Numerics = nargin - 3; % Rely on the user to pass the correct number of parameters
DDECommand = sprintf('SetSolve,%i,%i,%i', Surface, Code, SolveType);
switch Numerics
    case {1}, DDECommand = [DDECommand sprintf(',%11.9f', varargin{1})];
    case {2}, DDECommand = [DDECommand sprintf(',%11.9f,%11.9f', varargin{1}, varargin{2})];
    case {3}, DDECommand = [DDECommand sprintf(',%11.9f,%11.9f,%11.9f', varargin{1}, varargin{2}, varargin{3})];
end
Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);
[col, count, errmsg] = sscanf(Reply, '%f,%f,%f,%f,%f', Numerics+1);
SolveData = col';
