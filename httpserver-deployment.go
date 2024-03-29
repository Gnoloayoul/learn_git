apiVersion: apps/v1
kind: Deployment
metadata:  
	name: httpserver  
	labels:    
		app: httpserver
spec:  
	replicas: 1  
	selector:    
		matchLabels:      
			app: httpserver  
	template:    
		metadata:      
			labels:        
				app: httpserver    
	spec:      
		imagePullSecrets:      
		- name: cloudnative      
		containers:      
		- name: httpserver  
		  image: fmeng.azurecr.io/httpserver:1.0        
		  ports:        
		  - containerPort: 8080
readinessProbe:    
 	httpGet:      
		path: /healthz      
		port: 8080      
		scheme: HTTP    
	initialDelaySeconds: 5    
	periodSeconds: 3
startupProbe:  
	httpGet:    
		path: /healthz    
		port: liveness-port  
	failureThreshold: 30  
	periodSeconds: 10
livenessProbe:  
	httpGet:    
		path: /healthz    
		port: 8080    
		httpHeaders:    
		- name: Custom-Header      
		value: Awesome  
	initialDelaySeconds: 3  
	periodSeconds: 3
