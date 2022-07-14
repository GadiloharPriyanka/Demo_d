

clc;
close all;
clear all;
% Read Colour Image and convert it to a grey level Image
% Display the original Image
mycolourimage = imread('D:\dip\3.jpg');
myimage = rgb2gray(mycolourimage);
subplot(3,3,1);
imshow(myimage); title('Original Image');
% Apply Prewitt Operator
% Display both horizontal and vertical Edges
Prewittsedg = edge(myimage,'prewitt');
subplot(3,3,6);
imshow(Prewittsedg,[]); title('Prewitt - Edges');
