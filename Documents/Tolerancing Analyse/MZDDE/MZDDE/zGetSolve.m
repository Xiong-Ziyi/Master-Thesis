function SolveData = zGetSolve(Surface, Code)
% zGetSolve - Requests data for solves and/or pickups on lens surfaces.
%
% Usage : SolveData = zGetSolve(Surface, Code)
%
% where Code is
% an integer code indicating which surface parameter the solve data is for. The solve data is returned in the following
% formats, depending upon the code value according to the following table.
% ------------------------|------------------------------------------------|
% zGetSolve Code         -|- Returned data format                          |
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
%
% See also zSetSolve.
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
% $Revision: 1.3 $

global ZemaxDDEChannel ZemaxDDETimeout
DDECommand = sprintf('GetSolve,%i,%i', Surface, Code);
Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);
% Decide how many numerics to scan for
switch Code
  case {0},       Numerics = 3;
  case {2, 3, 4}, Numerics = 2;
  case {1, 5, 6, 7, 8, 9, 10, 11, 12}, Numerics = 4;
  otherwise, Numerics = 3;
end
[col, count, errmsg] = sscanf(Reply, '%f,%f,%f,%f,%f', Numerics);
SolveData = col';
