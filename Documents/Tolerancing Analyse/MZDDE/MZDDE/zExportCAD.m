function Reply = zExportCAD(filename,filetype,numspline,first,last,rayslayer,lenslayer,exportdummy,usesolids,raypattern,numrays,wave,field,deletevignetted,dummythick,split,scatter,usepol)
% zExportCAD - Request Zemax DDE Server to export lens data in CAD (IGES, STEP or SAT) format.
%
% zExportCAD(filename,filetype,numspline,first,last,rayslayer,lenslayer,exportdummy,
% usesolids,raypattern,numrays,wave,field,deletevignetted,dummythick,split,scatter,usepol)
%
% filename    : Name of file to write.
% filetype    : The file type. Use 0 for IGES, 1 for STEP, 2 for SAT, and 3 for BDF.
% numspline   : The number of spline points to use (if required on certain entity types).
% first       : The First surface to export.
% last        : The last surface to export.
% rayslayer   : The layer to place ray data on.
% lenslayer   : The layer to place lens data on.
% exportdummy : Use 1 to export dummy surfaces, otherwise use 0.
% usesolids   : Use 1 to export surfaces as solids, otherwise use 0.
% raypattern  : The ray pattern. Use 0 for XY, 1 for X, 2 for Y, 3 for ring, 4 for list, 5 for none.
% numrays     : The number of rays.
% wave        : The wave number. Use 0 for all.
% field       : The field number. Use 0 for all.
% deletevignetted : Use 1 to delete vignetted rays, otherwise use 0.
% dummythick  : The dummy surface thickness in lens units.
% split       : Use 1 to split rays from NSC sources, otherwise use 0.
% scatter     : Use 1 to scatter rays from NSC sources, otherwise use 0.
% usepol      : Use 1 to use polarization when tracing NSC rays, otherwise use 0. Polarization is automatically 
%               selected if splitting is specified.
%
% There is a complexity in using this feature via DDE. The export of lens data may take a long time relative to
% the timeout interval of the DDE communication. Therefore, calling this data item will cause ZEMAX to launch an
% independent thread to process the request. Once the thread is launched, the return value is the string "Exporting
% filename". However, the actual file may take many seconds or minutes to be ready to use. To verify that the export
% is complete and the file is ready, use the zExportCheck data item. zExportCheck will return 1 if the export is still
% running, or 0 if it has completed. Generally, the zExportCheck function call will need to be placed in a loop which
% executes until zExportCheck returns 0. A typical loop test in MATLAB might look like this:
%
% while zexportcheck, end;
%
% If zExportCad returns "BUSY!" then the export thread is already running from a previous request, and the export
% will not be performed.
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
DDECommand = sprintf('ExportCAD,%s,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%i,%11.9f,%i,%i,%i',filename,filetype,numspline,first,last,rayslayer,lenslayer,exportdummy,usesolids,raypattern,numrays,wave,field,deletevignetted,dummythick,split,scatter,usepol);
Reply = ddereq(ZemaxDDEChannel, DDECommand, [1 1], ZemaxDDETimeout);

