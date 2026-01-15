function recoverZMXdt(SurfaceNumber,curve,conic,par)
% 发送拟合后的曲率数据至ZEMAX的LED
Code = 2;%Curvature (numeric).
zSetSurfaceData(SurfaceNumber, Code, curve);
% 发送拟合后的Conic数据至ZEMAX的LED
Code = 6;%Conic. (numeric)
zSetSurfaceData(SurfaceNumber, Code, conic);
% 发送拟合后的非球面par数据至ZEMAX的LED
    % zSetSurfaceParamVector.m中的代码需要修改一下
    % 将：'SetSurfaceParameter,%i,%i,%11.9f'修改为'SetSurfaceParameter,%i,%i,%11.19f'即可正确发送数据
ParameterVector = zSetSurfaceParamVector(SurfaceNumber, par);
% 更新数据至ZEMAX LED
Status = zPushLens(500);