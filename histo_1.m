
%practical 2
%Read an image,plot its histogram then do histogram equalization.comment
%about the results.

clc
clear all
close all
a=imread('D:\dip\3.jpg');
b=rgb2gray(a);
subplot(2,2,1);
imshow(b);
title('Original Grayscale Image');
subplot(2,2,3);
imhist(b);
title('Histogram of Original Grayscale Image');
j=histeq(b);
subplot(2,2,2);
imshow(j);
title('Image After Histogram Equalization');
subplot(2,2,4);
imshow(j);
title('Histogram Of Image After Histogram Equalization');

