function NSCSettings = zGetNSCSettings()
% zGetNSCData - Requests NSC settings from ZEMAX.
%
% Usage : NSCSettings = zGetNSCSettings
% Returns a row vector of numerics in the following order
% MaxIntersections, MaxSegments, MaxNesting, MinAbsoluteIntensity, MinRelativeIntensity, GlueDistance, MissRayLength
% These items are the maximum number of ray intersections, segments, nesting level, minimum absolute intensity,
% minimum relative intensity, and glue distance used for NSC ray tracing.
%
% See also zSetNSCSettings
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
Reply = ddereq(ZemaxDDEChannel, 'GetNSCSettings', [1 1], ZemaxDDETimeout);
[col, count, errmsg] = sscanf(Reply, '%f,%f,%f,%f,%f,%f,%f');
NSCSettings = col';
