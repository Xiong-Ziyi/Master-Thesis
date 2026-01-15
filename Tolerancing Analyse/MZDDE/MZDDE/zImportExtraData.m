function  Status = zImportExtraData(SurfaceNumber, FileName)
% zImportExtraData - imports extra data and grid surface data values into an existing surface.
%
% Usage : Status = zImportExtraData(SurfaceNumber, FileName)
%
% This import function is used to load extra data values for extra data surfaces from an ASCII file rather than
% by typing the numbers in directly. SurfaceNumber specifies which surface number should
% receive the data. Numerical data must be in the ASCII file exactly as it appears in the extra data spreadsheet.
% The format of the ASCII file is a single column of free-format numbers, and the file should end in the DAT
% extension. 
% 
% For details of the ASCII format for grid sag surfaces, see the Chapter on 'Surface Types' in the ZEMAX manual.
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
DDECommand = sprintf('ImportExtraData,%i,%s', SurfaceNumber, FileName);
Status = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);


