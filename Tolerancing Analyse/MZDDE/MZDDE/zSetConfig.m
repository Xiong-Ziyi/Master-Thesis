function ConfigData = zSetConfig(ConfigNumber)
% zSetConfig - Sets the configuration and updates the lens.
%
% Usage : ConfigData = zSetConfig(ConfigNumber)
%
% This function switches the current configuration number and updates the system. 
% For example, to switch to configuration 3, the call is zSetConfig(3)
% The returned row vector is formatted as follows:
% currentconfig, numberconfig, error
% The currentconfig is the new configuration number, which will be between 1 and the value of numberconfig.
% Normally, this will be the desired configuration requested in the item name, as long as it was a valid configuration
% number. The error code is the same as returned by the zGetUpdate item, and will be zero if the new current
% configuration is traceable. 
%
% See also zGetConfig
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
% $Revision: 1.2 $

global ZemaxDDEChannel
DDECommand = sprintf('SetConfig,%i', ConfigNumber);
Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1]);
[col,count,errmsg] = sscanf(Reply, '%i,%i,%i');
ConfigData = col';


