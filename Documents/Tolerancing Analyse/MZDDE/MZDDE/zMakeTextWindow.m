function Reply = zMakeTextWindow(FileName, ModuleName, WinTitle, SettingsData)
% zMakeTextWindow -  notifies ZEMAX that text data has been written to a file and may now be displayed as a ZEMAX
% child window.
%
% Usage : Reply = zMakeTextWindow(FileName, ModuleName, WinTitle, SettingsData)
%
% The primary purpose of this item is to implement user defined features in a client application, that look
% and act like native ZEMAX features.
% The filename is the full path and file name to the temporary file that holds the text data. This must be the same
% name as passed to the client executable in the command line arguments, if any. The modulename is the full path
% and executable name of the client program that created the text data. The wintitle is the string which defines the
% title ZEMAX should place in the top bar of the window.
% The settingsdata is a string of values delimited by spaces (not commas) which are used by the client to define
% how the data was generated. These values are only used by the client, not by ZEMAX. The settingsdata string
% holds the options and data that would normally appear in a ZEMAX 'settings' style dialog box. The settingsdata
% should be used to recreate the data if required. See 'How ZEMAX calls the client' for details on the settingsdata.
% A sample function call might look like this:
% zMakeTextWindow('C:\TEMP\ZGF002.TMP','C:\ZEMAX\FEATURES\CLIENT.EXE','ClientWindow','6 5 4 12.55');
% This call indicates that ZEMAX should open a text window, display the data stored in the file
% C:\TEMP\ZGF002.TMP, and that any updates or setting changes can be made by calling the client module
% C:\ZEMAX\FEATURES\CLIENT.EXE. The settingsdata string (used only by the client) is '6 5 4 12.55'.
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
DDECommand = sprintf('MakeTextWindow,%s,%s,%s',FileName, ModuleName, WinTitle, SettingsData);
Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);




