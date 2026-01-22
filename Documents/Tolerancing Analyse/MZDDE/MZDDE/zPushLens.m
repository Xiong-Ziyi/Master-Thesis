function Status = zPushLens(Timeout)
% zPushLens - Copy lens in the ZEMAX DDE server into the Lens Data Editor (LDE).
%
% Usage : Status = zPushLens(Timeout)
% zPushLens will take the lens currently loaded in the server's memory and push it into the Lens Data Editor.
% In older version of ZEMAX, a dialog box will appear from the ZEMAX main window asking the user for permission 
% to accept the lens data being pushed by the client. 
% More recent versions of ZEMAX will reject all zPushLens attempts (return value -999) unless permission is
% granted via a checkbox on the Editors tab of the general ZEMAX preferences dialog.
% The client will wait Timeout seconds before returning a timeout error.
% If the lens data in the LDE has not been saved, an additional dialog box may appear asking
% if the old data should be saved first. The returned string is the same as for the zGetUpdate function; after updating the
% newly pushed lens file. If a value other than 0 is returned, the Update failed, if -999 is returned, the lens could not
% be pushed into the LDE. If -998 is returned, the function timed out.
%
% See also zGetPath, zGetRefresh, zLoadFile, zGetUpdate and zSaveFile.
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

global ZemaxDDEChannel
Reply = ddereq(ZemaxDDEChannel, 'PushLens', [1 1], Timeout * 1000);
if (Reply==0)
   Status = -998;
   return;
else
   Status = str2num(Reply);
end


