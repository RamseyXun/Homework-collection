ÿ�����붼Ĭ����ͬʱҪ��train_set��validation_set��test_set�������ڴ����ļ�����
�Ѿ��ṩ�ã�Ҫ��������ֱ������Ӧ�ļ��а���Ӧ��ʽ�ģ���������

KNN:
  Ԥ����֤�����ݵĽӿڣ�
	tryk��MatrixType��standard��disType��
		MatrixType ��ѡ�onehot
		standard ��ѡ�original normalization
		disType ��ѡ� Manhattan  Euclidean �Լ� Cosine
  Ԥ����Լ����ݽӿڣ�
	predict��MatrixType��standard��disType��
	�÷�ͬ��

NB
  ���ࣺpredict(ModelType��predictType, alpha)
		ModelType ��ѡ�Multinomial   Bernoulli
                predictType ��ѡ�validate��Ԥ����֤��
                                    test��    Ԥ����Լ�
                alpha: 0~1 �����⸡����
  
  �ع飺predict(predictType, alpha)
        ��������ͬ����