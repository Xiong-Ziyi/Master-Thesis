function Status = zuiSaveFile()
% zuiSaveFile - Save a lens file from the ZEMAX DDE server, using File Save As dialog.
%
% Usage : Status = zuiSaveFile
%
% Identical to zSaveFile, except that the filename is obtained from the user through a dialog box.
%
% The status is returned as -999 if the user presses cancel, or the file could not be saved.
% A status of -998 is returned if the command times out.
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
[fn, pn] = uiputfile('*.zmx', 'Save ZEMAX Lens File');
FileName = [pn fn];
if (fn==0)
   Status = -999;
   return;
end
DDECommand = sprintf('SaveFile,%s',FileName);
Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);
if (Reply)
    Status = str2num(Reply);
else
    Status = -998;
end;




