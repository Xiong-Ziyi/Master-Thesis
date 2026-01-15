function varargout = ZEMAXBusy(varargin)
% ZEMAXBUSY M-file for ZEMAXBusy.fig
%      ZEMAXBUSY, by itself, creates a new ZEMAXBUSY or raises the existing
%      singleton*.
%
%      H = ZEMAXBUSY returns the handle to a new ZEMAXBUSY or the handle to
%      the existing singleton*.
%
%      ZEMAXBUSY('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in ZEMAXBUSY.M with the given input arguments.
%
%      ZEMAXBUSY('Property','Value',...) creates a new ZEMAXBUSY or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before ZEMAXBusy_OpeningFunction gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to ZEMAXBusy_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

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

% $Header: C:\\Projects\\RCS\\C\\Projects\\MZDDE\\ZEMAXBusy.m,v 1.2 2005-04-22 09:48:01+02 dgriffith Exp dgriffith $
% $Revision: 1.2 $

% Edit the above text to modify the response to help ZEMAXBusy

% Last Modified by GUIDE v2.5 25-Mar-2002 12:19:15

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @ZEMAXBusy_OpeningFcn, ...
                   'gui_OutputFcn',  @ZEMAXBusy_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin & isstr(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before ZEMAXBusy is made visible.
function ZEMAXBusy_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to ZEMAXBusy (see VARARGIN)

% Choose default command line output for ZEMAXBusy
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes ZEMAXBusy wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = ZEMAXBusy_OutputFcn(hObject, eventdata, handles)
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;
