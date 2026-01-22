function Reply = zGetTextFile(TextFileName, AnalysisType, SettingsFileName, Flag)
% zGetTextFile -  Request ZEMAX to save a text file for any analysis that supports text output.
%
% Usage : zGetTextFile(TextFileName, AnalysisType, SettingsFileName, Flag)
%
% The TextFileName is the name of the file to be created including the full path, name, and extension for the text file.
% The AnalysisType argument is a 3 character case-sensitive label that indicates the type of analysis to be performed.
% The 3 letter labels are identical to those used for the button bar in ZEMAX. A list of codes may be obtained by typing
% "help zemaxbuttons" at the Matlab prompt. The labels are case sensitive. If no label is provided or
% recognized, a standard raytrace will be generated.
% If a valid file name is used for the "settingsfilename" argument, ZEMAX will use or save the settings used to
% compute the text file, depending upon the value of the flag parameter.
% If the flag value is 0, then the default settings will be used for the graphic.
% If the flag value is 1, then the settings provided in the settings file, if valid, will be used to generate the text.
% If the data in the settings file is in anyway invalid, then the default settings will be used to generate the text.
% If the flag value is 2, then the settings provided in the settings file, if valid, will be used and the settings box for
% the requested feature will be displayed. After the user makes any changes to the settings the text will then be
% generated using the new settings.
% No matter what the flag value is, if a valid file name is provided for the settingsfilename, the settings used will
% be written to the settings file, overwriting any data in the file.
% Only text, and not graphic files, are supported by zGetTextFile.
%
% If the command has been completed within the timeout, the Reply is the string OK, otherwise the
% value 0 is returned.
%
% NB : The analysis is performed on the lens in the LDE, not the lens in the DDE server.
%
% See also zGetMetaFile, zOpenWindow, ZemaxButtons
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



% $Revision: 1.4 $

global ZemaxDDEChannel ZemaxDDETimeout
DDECommand = sprintf('GetTextFile,"%s",%s,"%s",%i',TextFileName, AnalysisType, SettingsFileName, Flag);
Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);

