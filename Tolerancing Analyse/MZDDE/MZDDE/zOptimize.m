function Merit = zOptimize(Cycles)
% zOptimize - Optimize the lens in the ZEMAX DDE server.
%
% Usage : Merit = zOptimize(Cycles)
% zOptimize calls the ZEMAX Damped Least Squares optimizer
% where Cycles is the number of cycles to run. The return value is the final merit function. If the merit function value
% returned is 9.0E+009, the optimization failed, usually because the lens or merit function could not be evaluated.
% If n is zero, the optimization runs in automatic mode. If n is less than zero, Optimize returns the current merit
% function, and no optimization is performed.
%
% Returns -1 if the optimisation did not complete within the timeout period.
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
DDECommand = sprintf('Optimize,%i',Cycles);
Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);
if (Reply)
    Merit = str2double(Reply);
else
    Merit = -1;
end

