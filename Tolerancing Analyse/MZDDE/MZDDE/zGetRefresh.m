function Status = zGetRefresh()
% zGetRefresh - Copy lens data from lenseditor to the ZEMAX DDE server lens buffer.
%
% Usage : Status = zGetRefresh
%
% This function causes ZEMAX to copy the lens data from the LDE into the stored copy of the server. The lens
% is then updated, which means ZEMAX recomputes all pupil positions, solves, and index data. If the lens can be
% updated, ZEMAX returns the value 0, otherwise, it returns -1. If the zGetUpdate returns -1, no ray tracing can
% be performed. Returns -2 if the command times out.
% All subsequent commands will now affect or be executed upon the newly copied lens data. The old lens data,
% if any, cannot be recovered. 
%
% See also zGetUpdate and zPushLens.
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
Reply = ddereq(ZemaxDDEChannel, 'GetRefresh', [1 1], ZemaxDDETimeout);
if (Reply) 
    Status = str2num(Reply);
else
    Status = -2;
end

    

