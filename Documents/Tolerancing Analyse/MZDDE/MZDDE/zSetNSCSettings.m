function NSCSettings = zSetNSCSettings(MaxInt, MaxSeg, MaxNest, MinAbsI, MinRelI, GlueDist, MissRayDist)
% zSetNSCSettings - Sets NSC settings in ZEMAX.
%
% Usage : NSCSettings = zSetNSCSettings(MaxInt, MaxSeg, MaxNest, MinAbsI, MinRelI, GlueDist, MissRayDist)
% Returns a row vector of the new settings in the following order
% MaxInt, MaxSeg, MaxNes, MinAbsI, MinRelI, GlueDist, MissRayDist
% These items are the maximum number of ray intersections, segments, nesting level, minimum absolute intensity,
% minimum relative intensity, and glue distance used for NSC ray tracing.
%
% See also zGetNSCSettings
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
DDECommand = sprintf('SetNSCSettings,%i,%i,%i,%11.9f,%11.9f,%11.9f,%11.9f', MaxInt, MaxSeg, MaxNest, MinAbsI, MinRelI, GlueDist, MissRayDist);
Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);
[col, count, errmsg] = sscanf(Reply, '%f,%f,%f,%f,%f,%f,%f');
NSCSettings = col';
