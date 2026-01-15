function [Array,pv]=Add_PVrnd(Ary,Amp)
% Array:加入PV后的数组
% Amp:Ary数组中需要随机加的PV波动峰谷值
% pv：Array与Ary对比实际增加的峰谷值
Array=Ary+Amp.*randn(size(Ary));
pv=max(Array-Ary);