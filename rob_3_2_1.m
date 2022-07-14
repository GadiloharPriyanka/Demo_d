
clc;
close all;
clear all;
% Read Colour Image and convert it to a grey level Image
% Display the original Image
mycolourimage = imread('D:\dip\1.jpg');
myimage = rgb2gray(mycolourimage);
subplot(3,3,1);
imshow(myimage); title('Original Image');
% Apply Roberts Operator
% Display both horizontal and vertical Edges
robertsedg = edge(myimage,'roberts');
subplot(3,3,5);
imshow(robertsedg,[]); title('Roberts - Edges')
