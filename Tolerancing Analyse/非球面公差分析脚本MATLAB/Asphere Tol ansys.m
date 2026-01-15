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

PV=0.001;% uint:mm

SurfaceNumber=2;

%% 获取ZEMAX软件中的面型数据
zGetRefresh;% 从ZEMAX中复制一份设计文件至内存
% 获取面数据
zsSurfaceData = zsGetSurfaceData(SurfaceNumber);
r=linspace(-1.*zsSurfaceData.semidia,zsSurfaceData.semidia,129)';%按口径129的采样点采样
% 获取非球面参数
curve = zGetSurfaceData(SurfaceNumber,2);%曲率
conic = zGetSurfaceData(SurfaceNumber,6);%conic
par   = zGetSurfaceParamVector(SurfaceNumber);% par0~par12

for i=1:length(r)
    SagData(i,:) = zGetSag(SurfaceNumber,r(i) , 0);%获取面失高数据
end

y = SagData(:,1);% 提取原始失高数据

%% 拟合面型，输出非球面系数
while 1
    [yy,~]=Add_PVrnd(y,PV*2.5);%面失高数据加入加工误差PV，RMS值
    % 拟合方程：y=f(r)=((c*r^2)/(1+sqrt(1-(1+k)*c^2*r^2)))+a1*r^2+a2*r^4+a3*r^6+a4*r^8;
    [fitresult, gof] = createFit(r, yy);
    %提取拟合后的系数
    a1=fitresult.a1;a2=fitresult.a2;a3=fitresult.a3;a4=fitresult.a4;
    c=fitresult.c;k=fitresult.k;cR=1/c;
    % 计算拟合后的曲线与理论曲线的pv值和rms值
    yyy=((c.*r.^2)./(1+sqrt(1-(1+k).*c.^2.*r.^2)))+a1.*r.^2+a2.*r.^4+a3.*r.^6+a4.*r.^8;
    delta = y-yyy;
    pv = max(delta(1+11:129-11))- min(delta(1+11:129-11));rmsValue = rms(delta(1+11:129-11));
    disp(['pv:',num2str(pv*1000),'um. RMS:',num2str(rmsValue*1000),'um. RMS ≈ 1/',num2str(round(pv/rmsValue,1)),'PV']);
    if pv>=PV-0.1*PV && pv<=PV+0.15*PV && ...
        round(pv/rmsValue)>=2 && round(pv/rmsValue)<=5
        disp('PV、RMS 符合要求.')
        break;
    else
        a1=[];a2=[];a3=[];a4=[];c=[];k=[];
    end
end
plot(r,delta.*1000);% 拟合面型残差图，纵坐标：um，横坐标:口径

%% 将加入pv和RMS的面型数据输入到ZEMAX中
% 发送拟合后的曲率数据至ZEMAX的LED
Code = 2;%Curvature (numeric).
zSetSurfaceData(SurfaceNumber, Code, c);
% 发送拟合后的Conic数据至ZEMAX的LED
Code = 6;%Conic. (numeric)
zSetSurfaceData(SurfaceNumber, Code, k);
% 发送拟合后的非球面par数据至ZEMAX的LED
ParamVector(1:4) = [a1,a2,a3,a4];%8阶非球面
for i =1:4
    % zSetSurfaceParameter.m中的代码需要修改一下
    % 将：'SetSurfaceParameter,%i,%i,%11.9f'修改为'SetSurfaceParameter,%i,%i,%11.19f'即可正确发送数据
    ParameterData = zSetSurfaceParameter(SurfaceNumber, i, ParamVector(i));
end
% 更新数据至ZEMAX LED
Status = zPushLens(500);

disp('已暂停，按任意键恢复原始非球面参数；按Ctrl+C 终止程序');pause();

%% 恢复原始非球面参数
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
disp('Done!');

