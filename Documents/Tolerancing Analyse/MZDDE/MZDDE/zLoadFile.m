function Status = zLoadFile(FileName)
% zLoadFile - Load a lens file into the ZEMAX DDE server.
%
% Usage : Status = zLoadFile(FileName)
%
% Note that loading a file does not change the data displayed in the LDE;
% the server process has a separate copy of the lens data. The file name to be loaded is appended to the LoadFile
% item name, and must include the full path. For example: zLoadFile('C:\ZEMAX\SAMPLES\COOKE.ZMX'). The
% returned value is the same as for the zGetUpdate item; after updating the newly loaded lens file. If a value other
% than 0 is returned, the Update failed, if -999 is returned, the file could not be loaded. 
% If -998 is returned, the command timed out.
%
% See also zGetPath, zSaveFile, zPushLens, zuiLoadFile
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
DDECommand = sprintf('LoadFile,%s',FileName);
Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);
if (Reply), Status = str2num(Reply); else Status = -998; end;

