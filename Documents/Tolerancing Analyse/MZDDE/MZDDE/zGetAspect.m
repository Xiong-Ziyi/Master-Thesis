function AspectRatio = zGetAspect(FileName)
% zGetAspect - Returns the aspect ratio of a Zemax graphics or print window.
%
% zGetAspect(FileName)
%
% where filename is the name of the temporary file associated with the window being created or updated. If the
% temporary file name is the empty string ''; then the default aspect ratio and width (or height) is returned.
%
% This function extracts the graphic display aspect ratio and the width or height of the printed page in current lens
% units. For example, If the current aspect ratio is 3 x 4, the aspect ratio returned will be 0.75. Knowing the correct
% aspect ratio is required when drawing isometric plots. The format of the returned row vector is aspect, width. If the aspect
% ratio is greater than 1, then the plot is taller than it is wide, and the format of returned row vector is aspect, height.
% 
% See Also : zMakeGraphicWindow, zMakeTextWindow
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
if size(FileName,2) == 0
  DDECommand = 'GetAspect';
else 
  DDECommand = sprintf('GetAspect,%s', FileName);
end
Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);
[cols, count, errmsg] = sscanf(Reply, '%f,%f');
AspectRatio = cols';
