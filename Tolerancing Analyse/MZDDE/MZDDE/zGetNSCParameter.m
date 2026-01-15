function NSCParameter = zGetNSCParameter(SurfaceNumber, ObjectNumber, ParameterNumber)
% zGetNSCParameter - Requests parameter data for NSC objects present in ZEMAX.
%
% Usage : Parameter = zGetNSCParameter(SurfaceNumber, ObjectNumber, ParameterNumber)
% SurfaceNumber and ObjectNumber refer to the surface number and object number, and ParameterNumber is the 
% integer parameter number. The numerical parameter value is returned. If the command times out the value NaN is
% returned (Not-a-Number).
%
% See also zSetNSCParameter
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
DDECommand = sprintf('GetNSCParameter,%i,%i,%i',SurfaceNumber, ObjectNumber, ParameterNumber);
Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);
if (Reply), NSCParameter = str2num(Reply); else NSCParameter = NaN; end;




