function BufferData = zGetBuffer(n,TempFile)
% zGetBuffer  - Retrieve Zemax DDE client specific data from a window being updated
%
% zGetBuffer(n,TempFile)
% where n is the buffer number, which must be between 0 and 15 inclusive; and TempFile is the name of the
% temporary file for the window being updated. The tempfile name is passed to the client when ZEMAX calls the
% client; see the discussion "How ZEMAX calls the client" in the ZEMAX manual. Note each window may have it’s 
% own buffer data, and ZEMAX uses the filename to identify the window for which the buffer contents are required. 
%
% The buffer data is returned in an unscanned string.
%
% See also zSetBuffer.
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
DDECommand = sprintf('GetBuffer,%i,%s',n,TempFile);
BufferData = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);

