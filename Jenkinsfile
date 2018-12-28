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
                dir('blue_bear_code_challenge/encode_decode_algorithms/Debug')
                {
                sh '''
                    
		    make clean
		    make
                '''
	        }
                dir('blue_bear_code_challenge/file_encode_decode/Debug')
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
