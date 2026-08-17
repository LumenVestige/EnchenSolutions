1. 已经补充
2. 已经补充
  2.1 support-service后端是集群内部访问，front前端需要公网入口
3. 收到,抱歉，已经修改
  3.1 收到，已经补充
  3.2 support
  3.3 依旧使用 public
  3.4 请由运维创建并通过 Kubernetes Secret 注入：- DB_USER - DB_PASSWORD
以下为补充提示
 ▏1. Dockerfile                                                                                                                                                 
 ▏   - 后端 support-service 已提供多阶段构建 Dockerfile。                                                                                                        
 ▏   - 前端 support-center-front 已提供 Node 构建 + Nginx 运行的多阶段 Dockerfile。                                                                              
 ▏   - 两个运行镜像均使用非 root 用户。                                                                                                                          
 ▏ 2. Kubernetes manifests                                                                                                                                       
 ▏   - 后端已补充：                                                                                                                                              
 ▏     - ConfigMap                                                                                                                                               
 ▏     - Secret 模板                                                                                                                                             
 ▏     - Deployment                                                                                                                                              
 ▏     - Service                                                                                                                                                 
 ▏     - production 手动 migration Job 模板                                                                                                                      
 ▏   - 前端已补充：                                                                                                                                              
 ▏     - ConfigMap                                                                                                                                               
 ▏     - Deployment                                                                                                                                              
 ▏     - Service                                                                                                                                                 
 ▏     - 可选公网 Ingress 模板                                                                                                                                   
 ▏   - 前后端 Service 均使用 ClusterIP。                                                                                                                         
 ▏   - 后端集群内地址：http://support-service:8083。                                                                                                             
 ▏   - 公网只暴露前端 Ingress，前端 Nginx 将 /api/ 代理到后端。                                                                                                  
 ▏   - 后端、PostgreSQL、Redis 不直接暴露公网。                                                                                                                  
 ▏ 3. 数据库迁移安全                                                                                                                                             
 ▏   - 已彻底移除 down、clear-data 命令入口。                                                                                                                    
 ▏   - 当前只允许：                                                                                                                                              
 ▏     - init                                                                                                                                                    
 ▏     - up                                                                                                                                                      
 ▏     - status                                                                                                                                                  
 ▏     - create-admin                                                                                                                                            
 ▏   - 非法或危险命令会在连接数据库前直接退出。                                                                                                                  
 ▏   - stg：DATABASE_MIGRATION_ENABLED=true，容器启动自动执行 Bun init、up。                                                                                     
 ▏   - production：自动迁移关闭，发布前通过审批后的一次性 Kubernetes Job 手动执行 up。                                                                           
 ▏   - production Job 不包含回滚或清库命令。                                                                                                                     
 ▏ 4. 数据库配置                                                                                                                                                 
 ▏   - Database：support                                                                                                                                        
 ▏   - Schema：public                                                                                                                                            
 ▏   - 配置加载会拒绝非 public schema。                                                                                                                          
 ▏   - 本地测试账号：local_support / local_support。                                                                                                             
 ▏   - stg / production 用户名和密码请由运维创建并通过 Kubernetes Secret 注入：                                                                                  
 ▏     - DB_USER                                                                                                                                                 
 ▏     - DB_PASSWORD                                                                                                                                             
 ▏   - 真实凭据不会提交到 Git、ConfigMap 或 Deployment。                                                                                                         
 ▏ 5. 敏感参数                                                                                                                                                   
 ▏   - 数据库、Redis、JWT 私钥全部由后端 Secret 注入。                                                                                                           
 ▏   - 仓库只保留 secret.example.yaml 键名模板，不包含真实凭据。                                                                                                 
 ▏   - 前端无运行时敏感参数，因此不单独创建应用 Secret；Ingress TLS Secret 由证书管理系统提供。                                                                  
 ▏ 6. 镜像占位参数                                                                                                                                               
 ▏   - manifests 中镜像使用 <registry>/...:<stg-commit> 占位。                                                                                                   
 ▏   - 请在实际部署时替换为镜像仓库地址和不可变 commit tag。                                                                                                     
 ▏   - Ingress 中 <stg-support-host> 需要替换为实际 stg 域名。