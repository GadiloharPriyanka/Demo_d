%practical 3
%Read an image and to extract 8 different planes i.e 'bit plane slicing."
A=imread('D:\dip\1.jpg');
B=zeros(size(A));
B=bitset(B,8,bitget(A,8));
B=bitset(B,7,bitget(A,7));
B=bitset(B,6,bitget(A,6));
B=bitset(B,5,bitget(A,5));
B=bitset(B,4,bitget(A,4));
B=bitset(B,3,bitget(A,3));
B=bitset(B,2,bitget(A,2));
B=uint8(B);
figure,imshow(B);

