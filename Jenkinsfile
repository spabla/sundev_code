pipeline {
    agent any
    stages {
        stage('Build') {
            steps {
                sh 'echo "Building Utilities"'
                sh '''
                    cd pwd()/blue_bear_code_challenge/utilities/Debug
		    make clean
		    make
                '''
            }
        }
    }
}