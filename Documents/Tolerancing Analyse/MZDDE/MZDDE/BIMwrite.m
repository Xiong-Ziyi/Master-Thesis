function BIMwrite(image, BIMfilename)
% BIMwrite - write ZEMAX format BIM file from a double image array.
%
% Usage : BIMWrite(Image, BIMfilename);
%
% Writes ZEMAX style BIM image to the given file. The .bim file extension will be appended.
% See Geometric Image Analysis in the Analysis Menu chapter of the ZEMAX Manual.
% Currently ZEMAX only supports BIM files generated from square image arrays.

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


% Copyright 2003, Defencetek, CSIR
% $Revision: 1.0 $

fid = fopen([BIMfilename '.bim'], 'wb');
if fid == -1
    disp(['Unable to open file ' BIMfilename '.bim']);
else
    fwrite(fid, uint32(size(image,2)), 'uint32');
    fwrite(fid, uint32(size(image,1)), 'uint32');
    fwrite(fid, double(image), 'double');
end
fclose(fid);

