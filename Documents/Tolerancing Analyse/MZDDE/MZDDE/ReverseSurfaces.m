function Status = ReverseSurfaces(FirstSurface, LastSurface)
% ReverseSurfaces - Reverses a series of surfaces in a lens.
%
% Usage : Reply = ReverseSurfaces(FirstSurface, LastSurface)
% 
% The surfaces FirstSurface to LastSurface are reversed. This function is performed by first putting these surfaces into
% double pass using the DoublePass function, and then deleting the old surfaces. This approach has major limitations,
% including (but not limited to) the limitations of the DoublePass routine. In particular, all pickups, variables and
% solves are lost for the reversed surfaces.
%
% See also : DoublePass
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


% Firstly, sic the DoublePass routine on the surfaces and update the lens
Status = DoublePass(FirstSurface, LastSurface);
if (Status == 0), % Everything seems to be going right
  zGetUpdate;

  % Then make all lens data fixed for new surfaces and update again
  zFixAllSurfaceData(LastSurface:(2 * LastSurface - FirstSurface));
  zGetUpdate;

  % and delete the old surfaces
  for Surf = FirstSurface:(LastSurface-1),
      zDeleteSurface(FirstSurface);
  end;
end;
