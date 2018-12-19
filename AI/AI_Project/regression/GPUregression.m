function []=GPUregression()
    clear;
    Train = load('train.txt');
    Test =load('test.txt');
    load('GPUseed.mat');
    [train_row, train_col] = size(Train);
    %%���ýڵ���[�����,xx,...,xx,�����],��������
    Node = [train_col-1 ,200,200,1];
    layers = size(Node,2);
    step = [0.0050, 0.008,0.016];
    lambda = [0.00305 0.0050 0.00905];
    alpha=0.25;
    iter = 3000;
    thetaZero=1.5;
    thetaZero=gpuArray(thetaZero);
    G_Node=gpuArray(single(Node));
    G_step =gpuArray(single(step));
    G_lambda=gpuArray(single(lambda));
    G_iter=gpuArray(single(iter));
    G_alpha=gpuArray(single(alpha));
    %%----------��������----------------------------
    Train = single(Train);
    Test = single(Test);
    train_ans = Train( : , train_col);
    train_ans(1:8645)=train_ans(1:8645)*1.4;%����һ�±���
    test_ans=zeros(size(Test,1),1);
    test = mapminmax(Test( : , 1 : train_col-1)',0,1)';
    train  = mapminmax(Train( : , 1 : train_col - 1)',0,1)';%��һ��

    %%------��֤������---------------������֤������
    G_train=gpuArray(train(5726:14491,:));
    G_train_ans=gpuArray(train_ans(5726:14491,:));
    % G_val=gpuArray(train(13004:13747,:));
    % G_val_ans=gpuArray(train_ans(13004:13747,:));

    % G_val=gpuArray(train(13748:14491,:));
    % G_val_ans=gpuArray(train_ans(13748:14491,:));
    % 
    % G_val1=gpuArray(train(14492:15211,:));
    % G_val_ans1=gpuArray(train_ans(14492:15211,:));
    % 
    % G_val2=gpuArray(train(15212:15919,:));
    % G_val_ans2=gpuArray(train_ans(15212:15919,:));

    G_val3=gpuArray(train(15920:16637,:));
    G_val_ans3=gpuArray(train_ans(15920:16637,:));

    G_val=G_val3;
    G_val_ans=G_val_ans3;

     G_test=gpuArray(test);

    [MSE,corr,MSE_val,corr_val,out1,out2,best_w,best_b]= BPNN(G_train, G_val,ow,ob,G_iter,G_Node, layers,G_step,G_lambda,G_alpha,G_train_ans,G_val_ans,gpuArray(single(size(G_train_ans,1))),gpuArray(single(size(G_val_ans,1))));
    %--------------------------����Ϊ��ͼ������ ���ڲ�����
    % figure;
    % plot(1:iter, MSE, 'b');hold on
    % plot(1:iter, MSE_val, 'r');hold off
    % title('MSE');xlabel('��������'),ylabel('MSE');legend('ѵ����','��֤��');grid on;
    % ylim([0 10000]) ;
    % figure;
    % plot(1:iter, corr, 'b');hold on
    % plot(1:iter, corr_val, 'r');hold off
    % title('�����');xlabel('��������'),ylabel('�����');legend('ѵ����','��֤��');grid on;
    % 
    % figure;
    % stem(1:size(G_train_ans,1), G_train_ans, 'b','Marker','none');hold on
    % plot(1:size(G_train_ans,1), abs(out1),'r');hold off
    % title('����Ա�');xlabel('9-8��'),ylabel('cnt');legend('ʵ��ֵ','ģ�ͽ��');grid on;
    % 
    % figure;
    % stem(1:size(G_val_ans,1), G_val_ans, 'b','Marker','none');hold on
    % plot(1:size(G_val_ans,1), out2, 'r');hold off
    % title('����Ա�');xlabel('ѵ����'),ylabel('cnt');legend('ʵ��ֵ','ģ�ͽ��');grid on;
    %
    % [best1]=get_ans(G_val1,best_w,best_b,layers,G_alpha);
    % % figure;
    % % stem(1:size(G_val_ans1,1), G_val_ans1, 'b','Marker','none');hold on
    % % plot(1:size(G_val_ans1,1), best1, 'r');hold off
    % % title('����Ա�����1');xlabel('9��'),ylabel('cnt');legend('ʵ��ֵ','ģ�ͽ��');grid on;
    % Rmse1=best1-G_val_ans1;
    % Rmse1=Rmse1'*Rmse1/size(G_val_ans1,1)
    % 
    % [best2]=get_ans(G_val2,best_w,best_b,layers,G_alpha);
    % % figure;
    % % stem(1:size(G_val_ans2,1), G_val_ans2, 'b','Marker','none');hold on
    % % plot(1:size(G_val_ans2,1), best2, 'r');hold off
    % % title('����Ա�����2');xlabel('10��'),ylabel('cnt');legend('ʵ��ֵ','ģ�ͽ��');grid on;
    % Rmse2=best2-G_val_ans2;
    % Rmse2=Rmse2'*Rmse2/size(G_val_ans2,1)
    % 
    % [best3]=get_ans(G_val3,best_w,best_b,layers,G_alpha);
    % figure;
    % stem(1:size(G_val_ans3,1), G_val_ans3, 'b','Marker','none');hold on
    % plot(1:size(G_val_ans3,1), best3, 'r');hold off
    % title('����Ա�����3');xlabel('11��'),ylabel('cnt');legend('ʵ��ֵ','ģ�ͽ��');grid on;
    % Rmse3=best3-G_val_ans3;
    % Rmse3=Rmse3'*Rmse3/size(G_val_ans3,1)

    %%---------------------------��ò��Լ����-----------
    [best0]=get_ans(G_test,best_w,best_b,layers,G_alpha);
    stem(1:size(G_test,1), best0, 'b','Marker','none');
    sum(best0);
    csvwrite('66_v1.csv',round(abs(best0-thetaZero)));
end
function [MSE,corr,MSE_val,corr_val, out1, out2,best_w,best_b] = BPNN(train, val, w,theta,iter, Node, layers, step, lambda,alpha,train_ans, val_ans,train_row,val_row)
    Min_mse=10000;
%     w = cell(1, layers-1);
%     best_w=w;
    out = cell(1, layers - 1);
    out_val = cell(1, layers - 1);
    delta = cell(1, layers - 1);
%     theta = cell(1, layers - 1);
%     best_b=theta;
    layers=gpuArray(single(layers));
    MSE=gpuArray.zeros(1, iter,'single');
    MSE_val=gpuArray.zeros(1, iter,'single');
    corr=gpuArray.zeros(1,iter,'single');
    corr_val=gpuArray.zeros(1,iter,'single');
    
    
%%--------------��ʼ��Ȩֵ����----------------ʹ������
%     for i = 1 :layers-1
%         w{i} = gpuArray.rand(Node(i), Node(i+1),'single') - 0.5;
%         theta{i} = gpuArray.rand(1,Node(i+1),'single') -0.5;
%     end
%     ow=w;
%     ob=theta;
    h=waitbar(0,'iter');
    lens=gather(iter);
    cnt=1;
%%--------------����----------------------------
    for it = 1 : iter
        waitbar(cnt/lens,h,num2str(cnt));
        cnt=cnt+1;
%%------------���������--------------------
        %�����->���ز�
        out{1} = 1 ./ (1 + exp(-train *w{1} + theta{1}));%ѵ����
        out_val{1} = 1 ./ (1 + exp(-val *w{1} + theta{1}));%��֤��
        %���ز�
        for i=2 : layers-2
             out{i} =1 ./ (1 + exp(-out{i - 1} * w{i} + theta{i}));%ѵ����
             out_val{i} = 1 ./ (1 + exp(-out_val{i - 1} * w{i} + theta{i}));%��֤��
        end
        %�����
        out{layers-1} =  out{layers-2} * w{layers-1}  + theta{layers-1};%ѵ����
        out{layers-1}(out{layers-1}<0)=out{layers-1}(out{layers-1}<0)*alpha;%rule
        out_val{layers-1} = out_val{layers-2} * w{layers-1} + theta{layers-1};%��֤��
        out_val{layers-1}(out_val{layers-1}<0)=out_val{layers-1}(out_val{layers-1}<0)*alpha;%rule

%%-----------------���----����mse------------------        
        Err = train_ans - out{layers-1};
        tmp = Err;
        Err(Err<0)=Err(Err<0)*alpha;
        Err_val =  val_ans - out_val{layers-1};

        MSE(it) = tmp' * tmp / train_row;
        MSE_val(it) =  Err_val' * Err_val / val_row;
        
%%-------̰�Ĵ洢��֤��������w-----------------------        
        tmp=corrcoef(out{layers-1},train_ans);
        corr(it) = tmp(2,1);
%         tmp=corrcoef(out_val{layers-1},val_ans);
%         corr_val(it) = tmp(2,1);
        if(Min_mse > MSE_val(it))
            Min_mse = MSE_val(it);
            best_w=w;
            best_b=theta;
        end
        
%%--------����delta---------------------------------------
        %�����delta
        delta{layers-1} = (Err);
        %���ز�delta
        for i=layers-2 : -1 : 1
            delta{i} = out{i} .* (1-out{i}) .* (delta{i+1} * w{i+1}');
        end
%%-----------------------����w----------------------------
        %���ز�
        for i = layers-1 : -1 : 2
            w{i} = w{i} + step(i) *  (out{i-1}'*delta{i} / train_row  + lambda(i)  * w{i});
            theta{i} = theta{i} + step(i)  / train_row * sum(delta{i},1) ;
        end
        %�����->���ز�
        w{1} = w{1} + step(1)  *  (train' *delta{1} / train_row+ lambda(1)  * w{1});
        theta{1} = theta{1} + step(1)  / train_row * sum(delta{1},1) ;
    end
%%--------------------��֤����ѵ�������-------------
    out1 = out{layers-1};
    out2 = out_val{layers-1} ;
    close(h);
end

function [best]=get_ans(test,w,theta,layers,alpha)
    out = cell(1, layers - 1);
    out{1} = 1 ./ (1 + exp(-test *w{1} + theta{1}));
    for i=2 : layers-2
        out{i} =1 ./ (1 + exp(-out{i - 1} * w{i} + theta{i}));
    end
    %�����
    out{layers-1} =  out{layers-2} * w{layers-1}  + theta{layers-1};
    out{layers-1}(out{layers-1}<0)=out{layers-1}(out{layers-1}<0)*alpha;%rule
    best = out{layers-1};

end