COL = input('Degisken sayisi giriniz: ')
ROW = input('Denklem sayisi giriniz: ')
Scalars = []
FoundVariables = []
Answers = []


for i = 1:ROW
        A = []
    for j = 1:COL
        temp = input(sprintf('Denklem %d, Degisken %d icin deger girin: ', i, j))
        A = [A temp]
    end
    Scalars = [Scalars; A]
    temp = input(sprintf("Denklem %d icin cevabi yazin: ", i))
    Answers = [Answers; temp]
end

disp("Scalars: ")
disp(Scalars)
disp("Answers")
disp(Answers)

function x = GaussJordan(A,B);
  [row,col] = size(A);
n = row;
x = zeros(size(B));
for k = 1:n-1   
  for i = k+1:n
     carp = A(i,k) / A(k,k);
     for j=k+1:n
        A(i,j) = A(i,j) - carp * A(k,j);
     end
     B(i, :) = B(i, :) - carp * B(k, :);
  end
    x(n, :) = B(n, :) / A(n,n);
    for i = n-1:-1:1
        top = B(i, :);
        for j = i+1:n
            top = top - A(i,j) * x(j, :);
        end
        x(i, :) = top / A(i,i);
    end
end
endfunction

function x = InverseMethod(A,B);
  x = inv(A) * B;
endfunction
  
disp("--- INVERSE METODU ---");
disp(InverseMethod(Scalars, Answers));
disp("--- GAUSS JORDAN METODU ---");
disp(GaussJordan(Scalars, Answers));