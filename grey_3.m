clc;
close all;
clear all;
% Read Colour Image and convert it to a grey level Image
mycolourimage = imread('D:\dip\4.jpg');
myimage = rgb2gray(mycolourimage);
subplot(3,3,1);
imshow(myimage); title('Original Image');
sobelhz = edge(myimage,'sobel','horizontal');
subplot(3,3,2);
imshow(sobelhz,[]); title('Sobel - Horizontal Edges');
sobelvrt = edge(myimage,'sobel','vertical');
subplot(3,3,3);
imshow(sobelhz,[]); title('Sobel - Vertical Edges');
sobelvrthz = edge(myimage,'sobel','both');
subplot(3,3,4);
imshow(sobelvrthz,[]); title('Sobel - All edges');

