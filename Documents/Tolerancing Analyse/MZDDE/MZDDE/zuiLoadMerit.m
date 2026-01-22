function MeritData = zuiLoadMerit()
% zuiLoadMerit - Load a merit function file into the ZEMAX DDE server using File Open dialog box.
%
% Usage : MeritData = zuiLoadMerit
%
% Identical to zLoadMerit, except that the file name is obtained from the user via a File Open dialog box.
% Loads a ZEMAX .MF or .ZMX file and extracts the merit function and places it in the lens loaded in the server.
% Note that loading a merit function file does not change the data displayed in the LDE; the server process has a
% separate copy of the lens data. The file name must
% include the full path. For example: zLoadMerit('C:\ZEMAX\SAMPLES\MyMerit.MF'). The returned numeric vector is formatted
% as follows:
% number, merit
% where number is the number of operands in the merit function and merit is the value of the merit function. If
% the merit function value is 9.00e+009, the merit function cannot be evaluated.
%
% zuiLoadMerit returns -1 if the user presses cancel or selects a bad file.
%
% See also zOptimize
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
[fn, pn] = uigetfile('*.mf;*.zmx', 'Open ZEMAX Merit Function');
if (pn == 0)
   MeritData = -1;
   return;
end
FileName = [pn fn];
DDECommand = sprintf('LoadMerit,%s',FileName);
Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);
[col, count, errmsg] = sscanf(Reply, '%f,%f');
MeritData = col';




