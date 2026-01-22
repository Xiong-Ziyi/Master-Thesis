function Success = zSetMEMState(Surface, Object, AddressingMode, MirrorStateMatrix)
% Set the mirror states of a ZEMAX MEMS non-sequential digital mirror device (DMD or DLP).
%
% Usage : Success = zSetMEMState(Surface, Object, AddressingMode, MirrorStateMatrix)
%
% where the Surface is the Non-sequential group, and Object is the MEMS object within the group,
% the AddressingMode has the value 0, 1 or 2 for row addressing, column addressing or pixel addressing respectively.
% In the row or column mode, entire rows respectively columns of mirrors have the same state.
% MirrorStateMatrix is an array of integers having value 0, 1 or 2 only. In row or column addressing mode, MirrorStateMatrix
% must be a vector having the same number of rows respectively columns as the MEMS.
% In the pixel addressing mode, MirrorStateMatrix must have the same number of rows and columns as the MEMS.
% Returns 0 or 1 for failure and success respectively.
% This command will change the lens in the LDE.

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

% Copyright 2005, Defencetek, CSIR
% $Revision: 1.0 $
% $Author: dgriffith $


% First get a fresh copy of the lens in the LDE.
zGetRefresh;

% Check the type and mode of the MEMS surface
type = zgetnscobjectdata(Surface,Object,0);
if ~strcmp(type(1:4),'MEMS')
    error('This object is not a MEMS');
    
end

memsmode = zgetnscparameter(Surface,Object,9);
memscols = zgetnscparameter(Surface,Object,2);
memsrows = zgetnscparameter(Surface,Object,1);

staterows = size(MirrorStateMatrix,1);
statecols = size(MirrorStateMatrix,2);

% Check that the state array is within the range 0 - 2
for i=1:size(MirrorStateMatrix,1)
    for j=1:size(MirrorStateMatrix,2)
      if (MirrorStateMatrix(i,j) < 0) || (MirrorStateMatrix(i,j) > 2)
          error('MirrorStateMatrix must be in range 0 to 2.');
      end
    end
end

% Now check if the number of rows, column and/or pixels matches the size of the state matrix
% and set up the parameters of the MEMS.
switch memsmode
    case 0
        % Array is addressed by rows
        if (length(MirrorStateMatrix) ~= memsrows)
            error('Length of MirrorStateMatrix must be equal to number of rows in MEMS');
        end
        % Compute the number of parameters that must be set in the non-seq editor
        parms = floor(memsrows / 15)+1;
        for parm = 1:1:parms
            % Synthesize the value for the parameter
            bigX = 0;
            for therow = ((parm-1)*15+1):1:(parm*15)
                if therow <= memsrows
                    bigX = bigX + MirrorStateMatrix(therow) * 3^(rem(therow-1,15));
                end
            end
            % Set the parameter
            zsetnscparameter(Surface, Object, parm+9, bigX);
        end
    case 1
        % Array is addressed by columns
         if (length(MirrorStateMatrix) ~= memscols)
            error('Length of MirrorStateMatrix must be equal to number of columns in MEMS');
        end
        parms = floor(memscols / 15)+1;
        for parm = 1:1:parms
            % Synthesize the value for the parameter
            bigX = 0;
            for thecol = ((parm-1)*15+1):1:(parm*15)
                if thecol <= memscols
                    bigX = bigX + MirrorStateMatrix(thecol) * 3^(rem(thecol-1,15));
                end
            end
            % Set the parameter
            zsetnscparameter(Surface, Object, parm+9, bigX);
        end
        
    otherwise
        % Array is addressed by pixels
        if (staterows ~= memsrows) || (statecols ~= memscols)
            error('Size of MirrorStateMatrix is not the same as the MEMS');
        end
        parms = floor(memsrows * memscols / 15)+1;
        for parm = 1:1:parms
            % Synthesize the value for the parameter
            bigX = 0;
            for thepix = ((parm-1)*15+1):1:(parm*15)
                if thepix <= memscols * memsrows
                    bigX = bigX + MirrorStateMatrix(thepix) * 3^(rem(thepix-1,15));
                end
            end
            % Set the parameter
            zsetnscparameter(Surface, Object, parm+9, bigX);
        end       
end
Success = zpushlens(20);


