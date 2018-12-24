pipeline {
    agent any
    stages {
        stage('Build') {
            steps {
                sh 'echo "Building Utilities"'
                dir('blue_bear_code_challenge/utilities/Debug')
                {
                sh '''
                    
		    make clean
		    make
                '''
	        }
            }
        }
    }
}
