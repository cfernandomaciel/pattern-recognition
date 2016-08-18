apt_update 'Update the apt cache daily' do
	frequency 86_400
	action :periodic
end

package 'lxc'

bash 'Create container' do 
  user 'root'
  cwd  '/scripts'
  code <<-EOH
    ./create-container.sh    
  EOH
end

bash 'Create container' do 
  user 'root'
  cwd  '/scripts'
  code <<-EOH
    ./start-container.sh    
  EOH
end