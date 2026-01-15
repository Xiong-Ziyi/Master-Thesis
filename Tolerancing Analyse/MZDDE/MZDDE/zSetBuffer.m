function BufferData = zSetBuffer(BufferNumber, Text)
% zSetBuffer  - store client specific data with the window being created or updated.
%
% Usage : BufferData = zSetBuffer(BufferNumber, Text)
%
% The buffer data can be used to store user selected options, instead of using the settings data on the command line of the
% zMakeTextWindow or zMakeGraphicWindow items. The data must be in a string format. The syntax is:
% zSetBuffer(1,'any text you want......');
% There are 16 buffers provided, numbered 0 through 15, and each can be set using zSetBuffer(0,'.....'); zSetBuffer(1,'.....')etc. % 
% The string given is the only text that is stored; and it may be a maximum of 240 characters.
% Note the buffer data is not associated with any particular window until either the zMakeTextWindow or
% zMakeGraphicWindow items are issued. Once ZEMAX receives the MakeTextWindow or MakeGraphicWindow
% item, the buffer data is then copied to the appropriate window memory, and then may later be retrieved from that
% window's buffer using zGetBuffer. 
%
% See also GetBuffer.
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
DDECommand = sprintf('SetBuffer,%i,%s',BufferNumber, Text);
BufferData = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);


