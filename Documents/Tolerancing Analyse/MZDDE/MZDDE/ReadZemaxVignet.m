function zmxVignet = ReadZemaxVignet(File)
% zmxVignet = ReadZemaxVignet(File)
%
% Reads text written from a Zemax Vignetting (Vig) analysis.
% The text can be written from the Vignetting window, or generated using zGetTextFile with the 'Vig' code (see help ZemaxButtons)
% The results are returned in a struct in which the following fields are defined :
%      datatype: Type of data in e.g. 'Vignetting Data'
%          file: Name of the ZEMAX file from which the data was computed e.g. 'C:\Projects\MSMI\Concepts\baf(960)mak.ZMX'
%         title: Title of the ZEMAX file from which the data was computed e.g. 'mak U.S.Patent 2701983 Variant a'
%          date: Date on which the data was computed e.g. 'THU NOV 6 2003'
%    fieldunits: The units of the field position data (e.g. millimetres or degrees)
%         field: The field position data in fieldunits.
%           vig: The vignetting data.
%
% See also zGetTextFile

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



% $Revision: 1.1 $

[fid, err] = fopen(File, 'r');
if fid==-1
    disp(['Unable to open specified file ' File ' - ' err]);
    return;
end
nexlin = fgetl(fid);
zmxVignet.datatype = nexlin;
datacount = 0; % Count the data lines
while ~feof(fid) 
   nexlin = fgetl(fid);
   if length(nexlin) > 6 
       ident = nexlin(1:6);
   else
       ident = nexlin;
   end
   switch ident
       case 'File :' 
           zmxVignet.file = nexlin(8:(length(nexlin)));
       case 'Title:' 
           zmxVignet.title = nexlin(8:(length(nexlin)));
       case 'Date :' 
           zmxVignet.date = nexlin(8:(length(nexlin)));
       
       otherwise
           % Try various scans to see what the data might be
           [A, count] = sscanf(nexlin, 'Wavelength: %f ');
           if count == 1
               zmxVignet.wav = A(1);
              
           else
               [A, count] = sscanf(nexlin, '%f %f');
               if count == 2
                  % Presumably we have hit data, now stored as column vector in A
                  datacount = datacount + 1;
                  zmxVignet.field(datacount) = A(1);
                  zmxVignet.vig(datacount) = A(2);
               else
                   [A, count] = sscanf(nexlin, 'Field values are in %s');
                   if count == 1
                       zmxVignet.fieldunits = A;
                   else
                       % Put any new code in here
                   end
               end
                 
           end
   end

end

fclose(fid);
