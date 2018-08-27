function [VO,R] = ortogonaliza (A,eps)
    [m,n] = size(A);
    k=1;
    for j=1:m
        v{j} = A(j,:);
    end
    u1=v{1};
    if(abs(sum(u1))>eps)
        VO(k,:) = u1;
        k++;
    end
    u2= v{2}-(dot(v{2},u1)/sum((u1.^2)))*u1;
    if(abs(sum(u2))>eps)
        VO(k,:) = u2;
        k++;
        u3= v{3}-(dot(v{3},u2)/sum((u2.^2)))*u2-(dot(v{3},u1)/sum((u1.^2)))*u1;
        if(abs(sum(u3))>eps)
            VO(k,:) = u3;
        end
    else
        u3= v{3}-(dot(v{3},u1)/sum((u1.^2)))*u1
        if(abs(sum(u3))>eps)
            VO(k,:) = u3;
        end
    end
R=rank(VO);
end
