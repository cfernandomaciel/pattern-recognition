cd
wget http://ftp.unicamp.br/pub/apache/hadoop/core/current/hadoop-2.7.2-src.tar.gz

sudo tar zxf hadoop-2.7.2-src.tar.gz
sudo mv hadoop-2.7.2-src /etc/local/hadoop
sudo chown -R hduser:hadoop hadoop

cd