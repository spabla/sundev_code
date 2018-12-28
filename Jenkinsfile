pipeline {
    agent any
    stages {
        stage('Build Libs') {
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
        stage('Build Application') {
            steps {
                sh 'echo "Building Utilities"'
                dir('blue_bear_code_challenge/applications/morse_to_text/Debug')
                {
                sh '''
                    
		    make clean
		    make
                '''
	        }
                dir('blue_bear_code_challenge/applications/text_to_morse/Debug')
                {
                sh '''
                    
		    make clean
		    make
                '''
	        }
                dir('blue_bear_code_challenge/applications/test_suite_morse_encode_decode/Debug')
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
