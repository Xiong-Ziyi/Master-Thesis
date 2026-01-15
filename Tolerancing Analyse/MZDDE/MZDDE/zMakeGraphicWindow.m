function Reply = zMakeGraphicWindow(FileName, ModuleName, WinTitle, TextFlag, SettingsData)
% zMakeGraphicWindow -  notifies ZEMAX that graphic data has been written to a file and may now be displayed as a ZEMAX
% child window.
%
% Usage : Reply = zMakeGraphicWindow(FileName, ModuleName, WinTitle, TextFlag, SettingsData)
%
% The primary purpose of this item is to implement user defined features in a client application, that
% look and act like native ZEMAX features. 
% FileName is the full path and file name to the temporary file that holds the graphic data. This must be the
% same name as passed to the client executable in the command line arguments, if any. The ModuleName is the
% full path and executable name of the client program that created the graphic data. The WinTitle is the string which
% defines the title ZEMAX should place in the top bar of the window.
% The TextFlag should be 1 if the client can also generate a text version of the data. Since the current data is a
% graphic display (it must be if the call is to zMakeGraphicWindow) ZEMAX wants to know if the "Text" menu option
% should be available to the user, or if it should be grayed out. If the text flag is 0, ZEMAX will gray out the "Text"
% menu option and will not attempt to ask the client to generate a text version of the data.
% The settings data is a string of values delimited by spaces (not commas) which are used by the client to define
% how the data was generated. These values are only used by the client, not by ZEMAX. The settings data string
% holds the options and data that would normally appear in a ZEMAX "settings" style dialog box. The settings data
% should be used to recreate the data if required. See "How ZEMAX calls the client" for details on the settings data.
% A sample call might look like this:
% zMakeGraphicWindow('C:\TEMP\ZGF001.TMP','C:\ZEMAX\FEATURES\CLIENT.EXE','ClientWindow',1, '0 1 2 12.55');
% This item indicates that ZEMAX should open a graphic window, display the data stored in the file
% C:\TEMP\ZGF001.TMP, and that any updates or setting changes can be made by calling the client module
% C:\ZEMAX\FEATURES\CLIENT.EXE. This client can generate a text version of the graphic, and the settings data
% string (used only by the client) is '0 1 2 12.55'.
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
DDECommand = sprintf('MakeGraphicWindow,%s,%s,%i,%s',FileName, ModuleName, WinTitle, TextFlag, SettingsData);
Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);



