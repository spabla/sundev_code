pipeline {
    agent any
    stages {
        stage('Build') {
            steps {
                sh 'echo "Building Utilities"'
                sh '''
		    ./blue_bear_code_challenge/utilities/Debug/make clean
		    ./blue_bear_code_challenge/utilities/Debug/make
                '''
            }
        }
    }
}
