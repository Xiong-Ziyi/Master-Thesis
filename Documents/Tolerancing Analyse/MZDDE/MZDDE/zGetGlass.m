function [GlassName,nd,vd,dpgf] = zGetGlass(SurfaceNumber)
% zGetGlass - Requests data on the glass at a lens surface from the Zemax DDE server.
%
% Usage : [GlassName,nd,vd,dpgf] = zGetGlass(SurfaceNumber)
% 
% name is the glass name as a string, nd is the refractive index at the d line, vd is the Abbe dispersion and 
% dpgf is the relative partial dispersion. The last three are numeric.
%
% If the specified surface is not valid, is not made of glass, or is gradient index, the returned vector is empty.
% Data may be meaningless for glasses defined only outside of the FdC band.
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
DDECommand = sprintf('GetGlass,%i',SurfaceNumber);
Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);
if size(Reply,2) > 1
   [GlassName, Reply] = strtok(Reply, ' ,');
   [col, count, errmsg] = sscanf(Reply, ',%f,%f,%f');
   nd = col(1);
   vd = col(2);
   dpgf = col(3);
else
   GlassName = [];
   nd = []; vd = []; dpgf = [];
end




