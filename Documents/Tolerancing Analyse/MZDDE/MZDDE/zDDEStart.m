function Status = zDDEStart()
% zDDEStart - Establish DDE link with the Zemax server. If no ZEMAX running,
% find and start ZEMAX.
%
% Usage : Status = zDDEStart
%
% Returns 0 if a DDE channel to ZEMAX was opened successfully. If not, -1
% is returned. If ZEMAX is not running, an attempt will be made to find and
% start ZEMAX. Failure will return -1.
%
% Using this function may open a redundant DOS command window.
%
% This function also sets the timeout for all ZEMAX DDE calls to 3 seconds.
%
% See also zDDEClose, zDDEInit
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
ZemaxDDEChannel = ddeinit('zemax', '');
if (ZemaxDDEChannel)
    Status = 0; return;
else
    Found = 0;
    % First look in Program Files directory for ZEMAX
    Lookin = 'c:\Program Files\';
    RootDir = dir([Lookin '*.*']);
    for i = 1:length(RootDir),
        if (findstr(RootDir(i).name, 'ZEMAX'))&(RootDir(i).isdir)
            Found = i;
        end
    end
    
    % If not found, look in the root directory of the c drive
    if ~Found
     Lookin = 'c:\';
     RootDir = dir([Lookin '*.*']);
     for i = 1:length(RootDir),
         if (findstr(RootDir(i).name, 'ZEMAX'))&(RootDir(i).isdir)
             Found = i ;
         end
     end
    end
    
    if (Found)
        ZEMAXexe = [Lookin RootDir(Found).name '\zemax.exe'];
        if exist(ZEMAXexe)
            dos([ZEMAXexe ' &']);
            % Try communicating with ZEMAX every second for next 15 seconds
            pause(1);
            Status = zDDEInit;
            for t=1:15
                pause(1);
                Status = zDDEInit;
                if Status == 0
                    break;
                end
            end
        else
            Status = -1;
        end
    else
        Status = -1;
    end
end        
ZemaxDDETimeout = 3000;    
