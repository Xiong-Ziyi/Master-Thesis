function PlotZemaxOTF(zmxOTF)
% PlotZemaxOTF(zmxOTF)
%
% Expects a structure according to the format returned by ReadZemaxOTF or zGetMTF.
% Plots the thru-frequency OTF/MTF data.

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


% Copyright 2003, Defencetek, CSIR
% $Revision: 1.7 $

figure;
plot(zmxOTF.abscis, zmxOTF.data);

if length(zmxOTF.wav) == 2
  title([zmxOTF.title sprintf(' %6.4f to %6.4f micron', zmxOTF.wav(1), zmxOTF.wav(2))]);
else
  title([zmxOTF.title sprintf(' %6.4f micron', zmxOTF.wav(1))]);
end

if isempty(findstr(zmxOTF.datatype, 'Through Focus')) && isempty(findstr(zmxOTF.datatype, 'Field Height')) % Then this is a thru-frequency plot
    xlab = [zmxOTF.colhead{1} ' (' zmxOTF.sfrequnits ')']; % Add the units to the x label
else
    xlab = zmxOTF.colhead{1}; % Don't bother with units - maybe a bit unfriendly
end
xlabel(xlab);
ylabel(zmxOTF.datatype);
grid;

if ~isempty(findstr(zmxOTF.datatype, 'MTF'))
  axis([min(zmxOTF.abscis) max(zmxOTF.abscis) 0 1]);
end



if ~isempty(findstr(zmxOTF.datatype, 'Field Height')) % This is a thru-field MTF at a number of spatial frequencies
    % Set up the legends
    sfrequnits = strrep(zmxOTF.sfrequnits, 'cles per ', '/');
    for i = 1:zmxOTF.fcount
        leg{i*2-1} = [zmxOTF.colhead{2}(1) ' ' num2str(zmxOTF.sfreq(i)) ' ' sfrequnits];
        leg{i*2  } = [zmxOTF.colhead{3}(1) ' ' num2str(zmxOTF.sfreq(i)) ' ' sfrequnits];
    end
else % This is a through frequency or through focus plot, at a number of field points
    for i = 1:zmxOTF.fcount
        leg{i*2-1} = [zmxOTF.colhead{2}(1) ' ' zmxOTF.fieldpos{i}];
        leg{i*2  } = [zmxOTF.colhead{3}(1) ' ' zmxOTF.fieldpos{i}];
        
    end
end

% OK set up the legends
legend(leg);

