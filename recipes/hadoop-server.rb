apt_update 'Update the apt cache daily' do
	frequency 86_400
	action :periodic
end

package 'openjdk-7-jdk'
package 'software-properties-common'

apt_repository "java7-installer" do
	uri "http://ppa:webupd8team/java"
	components ["main"]
	keyserver "keyserver.ubuntu.com"
	key "EEA14886"
end

apt_update 'prepare for java downloading' do
	frequency 86_400
	action :periodic
end

package 'oracle-java7-installer'

#at /etc/default/lxc-net 
#uncomment the following line
#LXC_DHCP_CONFILE=/etc/lxc/dnsmasq.conf

#and create this content
#dhcp-host=hadoop11,10.0.1.111
#dhcp-host=hadoop12,10.0.1.112
#dhcp-host=hadoop13,10.0.1.113
#dhcp-host=hadoop14,10.0.1.114
#dhcp-host=hadoop15,10.0.1.115
#dhcp-host=hadoop16,10.0.1.116
#dhcp-host=hadoop17,10.0.1.117
#dhcp-host=hadoop18,10.0.1.118
#dhcp-host=hadoop19,10.0.1.119
#dhcp-host=hadoop21,10.0.1.121
#dhcp-host=hadoop22,10.0.1.122
#dhcp-host=hadoop23,10.0.1.123
#dhcp-host=hadoop24,10.0.1.124
#dhcp-host=hadoop25,10.0.1.125
#dhcp-host=hadoop26,10.0.1.126
#dhcp-host=hadoop27,10.0.1.127
#dhcp-host=hadoop28,10.0.1.128
#dhcp-host=hadoop29,10.0.1.129


#then at  /etc/hosts
#insert the following lines
#10.0.1.111	hadoop11
#10.0.1.112      hadoop12
#10.0.1.113      hadoop13
#10.0.1.114      hadoop14
#10.0.1.115      hadoop15
#10.0.1.116      hadoop16
#10.0.1.117      hadoop17
#10.0.1.118      hadoop18
#10.0.1.119      hadoop19
#10.0.1.121      hadoop21
#10.0.1.122      hadoop22
#10.0.1.123      hadoop23
#10.0.1.124      hadoop24
#10.0.1.125      hadoop25
#10.0.1.126      hadoop26
#10.0.1.127      hadoop27
#10.0.1.128      hadoop28
#10.0.1.129      hadoop29

#stop service
#service lxc-net stop

#rm /var/lib/misc/dnsmasq.lxcbr0.leases 
#service lxc-net start


bash 'Add group' do 
  user 'root'
  cwd  '/scripts'
  code <<-EOH
    ./add-group.sh    
  EOH
end


bash 'replace sysctl file' do 
  user 'root'
  cwd  '/scripts'
  code <<-EOH
    ./replace-sysctl.sh    
  EOH
end

bash 'download hadoop' do 
  user 'root'
  cwd  '/scripts'
  code <<-EOH
    ./download-hadoop.sh    
  EOH
end
