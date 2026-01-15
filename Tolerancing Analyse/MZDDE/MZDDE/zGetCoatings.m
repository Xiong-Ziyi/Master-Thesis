function CoatingList = zGetCoatings()
% zGetCoatings - Get a list of available coatings from the ZEMAX coatings.dat file
%
% Usage : CoatingList = zGetCoatings
%
% Returns a cell array of all available coatings in the coatings.dat file.
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
% $Revision: 1.1 $
% $Author: dgriffith $

[ZEMAXPath, LensPath] = zGetPath;
CoatingFile = [ZEMAXPath '\Coatings\COATING.DAT'];
CoatingFID = fopen(CoatingFile, 'rt');
Count = 0;
while 1
    tline = fgetl(CoatingFID);
    if ~ischar(tline), break, end
    [Token, Rest] = strtok(tline, ' ');
    if (strcmp(upper(Token),'COAT'))
        Count = Count+1;
        Token = strtok(Rest, ' ');
        CoatingList{Count} = Token;
    end
end
fclose(CoatingFID);
CoatingList = CoatingList';
