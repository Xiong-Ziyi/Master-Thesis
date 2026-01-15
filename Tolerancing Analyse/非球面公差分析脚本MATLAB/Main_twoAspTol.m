% 先确保安装了ZEMAX官方的matlab工具箱MZDDE
% 然后打开ZEMAX，然后在ZEMAX中打开对应的zmx文件。
clc;clear;close all;
global isStrat;
if isempty(isStrat) || isStrat==false
    rturn=zDDEInit;%建立与ZEMAX的通讯，返回0表示通讯正常
    isStrat= true;
    if rturn ~= 0
        disp("通讯失败！")
        return;
    end
end
SurfaceNumber1=3;
SurfaceNumber2=8;
PV=0.00075;% uint:mm

[a11,a21,a31,a41,c1,k1,curve1,conic1,par1]= SendSingleFitDt(SurfaceNumber1,PV);
pause(0.5);
[a12,a22,a32,a42,c2,k2,curve2,conic2,par2]= SendSingleFitDt(SurfaceNumber2,PV);

disp('已暂停，按任意键恢复原始非球面参数；按Ctrl+C 终止程序');pause();

recoverZMXdt(SurfaceNumber1,curve1,conic1,par1);
pause(0.5);
recoverZMXdt(SurfaceNumber2,curve2,conic2,par2);